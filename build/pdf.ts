import * as path from "@std/path";
import { execSync } from "node:child_process";
import fs from "node:fs";
import { PDFDocument } from 'npm:pdf-lib';

// const decoder = new TextDecoder();
// const metaData: Record<string, string> = JSON.parse(decoder.decode(Deno.readFileSync("./metadata.json")));
const dirname = import.meta.dirname;

const toIgnore = ['.git', '.vscode', 'build'];

const getFolderContent = (dir: string, Directories = true) => {
  if (!dirname) throw new Error("Failed to get subjects");

  return Array.from(Deno.readDirSync(dir))
    .filter(file => file.isDirectory == Directories && !toIgnore.includes(file.name));
};

const hasFolder = (files: Deno.DirEntry[], folderName: string) => {
  return files.some(file => file.isDirectory && file.name === folderName);
};



const generateCodeSnippet = (cppFilePath: string, outputDir: string): string => {
  const fileNameWithoutExt = path.basename(cppFilePath, ".cpp");
  const tempName = `${fileNameWithoutExt}_${Date.now()}`
  const outputFilePath = path.join(outputDir, `${tempName}.png`);
  execSync(`carbon-now ${cppFilePath} --save-to=${outputDir} --save-as=${tempName} --theme dracula`);

  if (!fs.existsSync(outputFilePath)) {
    throw new Error(`Snippet generation failed for: ${cppFilePath}`);
  }

  return outputFilePath;
};

const generatePdf = async (pdfDoc:PDFDocument , questionImagePath: string, codeSnippetImagePath: string) => {
  const questionImageBytes = fs.readFileSync(questionImagePath);
  const codeSnippetImageBytes = fs.readFileSync(codeSnippetImagePath);

 

  const page = pdfDoc.addPage();

  const questionImage = await pdfDoc.embedPng(questionImageBytes);
  const codeSnippetImage = await pdfDoc.embedPng(codeSnippetImageBytes);

  const codeSnippetDims = codeSnippetImage.scale(0.5);
  const questionDims = questionImage.scale(1);
  
  codeSnippetDims.width = Math.max(questionDims.width, codeSnippetDims.width * 0.7)
  codeSnippetDims.height = questionDims.width == codeSnippetDims.width ?  codeSnippetDims.height * 0.7 : codeSnippetDims.height
  // page.setSize(Math.max(questionDims.width, codeSnippetDims.width), questionDims.height + codeSnippetDims.height);
  page.setSize(codeSnippetDims.width, questionDims.height + codeSnippetDims.height);

  page.drawImage(questionImage, {
    x: 0,
    y: codeSnippetDims.height,
    width: codeSnippetDims.width,
    height: questionDims.height,
  });

  page.drawImage(codeSnippetImage, {
    x: 0,
    y: 0,
    width: codeSnippetDims.width,
    height: codeSnippetDims.height,
  });


};

const generateSubjectPdfs = async () => {
  const subjects = getFolderContent(path.join(dirname as string, ".."));

  for (const subject of subjects) {
    const subjectPath = path.join(dirname as string, "..", subject.name);
    const midFolder = hasFolder(Array.from(Deno.readDirSync(subjectPath)), "mid");
    const finalFolder = hasFolder(Array.from(Deno.readDirSync(subjectPath)), "final");

    if (midFolder) {
      await processFolder(subjectPath, 'mid');
    }
    if (finalFolder) {
      await processFolder(subjectPath, 'final');
    }
  }
};

const processFolder = async (subjectPath: string, period: string) => {
  const traceDir = path.join(subjectPath, period, 'tracing');
  const problemSolvingDir = path.join(subjectPath, period, 'problemSolving');
  const problemSolvingFiles = getFolderContent(problemSolvingDir, false).filter(file => file.name.endsWith(".cpp"));

  const traceFiles = getFolderContent(traceDir, false).filter(file => file.name.endsWith(".cpp"));
  let processing = 0;
  if(traceFiles.length > 0) {
  const tracePDF = await PDFDocument.create();
  const tracPDFPath = path.join(subjectPath, `tracing.pdf`);

  for (const file of traceFiles) {
    processing++
    console.log(`[${processing} / ${problemSolvingFiles.length + traceFiles.length}] ${file.name}`)
    const cppFilePath = path.join(traceDir, file.name);
    const questionImagePath = path.join(traceDir, file.name.replace(".cpp", ".png"));
  
    const codeSnippetImage = generateCodeSnippet(cppFilePath, traceDir);
    await generatePdf(tracePDF ,questionImagePath, codeSnippetImage);
    fs.unlinkSync(codeSnippetImage)
  }
  const tracePDFBytes = await tracePDF.save();
  fs.writeFileSync(tracPDFPath, tracePDFBytes);


}


if(problemSolvingFiles.length > 0) {

  const problemSolvingPDF = await PDFDocument.create();
  const problemSolvingPDFPath = path.join(subjectPath, `problemSolving.pdf`);
  for (const file of problemSolvingFiles) {
    processing++
    console.log(`[${processing} / ${problemSolvingFiles.length + traceFiles.length}] ${file.name}`)

    const cppFilePath = path.join(problemSolvingDir, file.name);
    const questionImagePath = path.join(problemSolvingDir, file.name.replace(".cpp", ".png"));

    const codeSnippetImage = generateCodeSnippet(cppFilePath, problemSolvingDir);
    await generatePdf(problemSolvingPDF,questionImagePath, codeSnippetImage);
    fs.unlinkSync(codeSnippetImage)
 
  }
  const problemSolvingPDFBytes = await problemSolvingPDF.save();
  fs.writeFileSync(problemSolvingPDFPath, problemSolvingPDFBytes);

}
};

await generateSubjectPdfs();
