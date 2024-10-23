import * as path from "@std/path";
import { execSync } from "node:child_process";
import fs from "node:fs";
import { PDFDocument , rgb , StandardFonts  } from 'npm:pdf-lib';

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
  while(true){
  try{

    execSync(`carbon-now ${cppFilePath} --save-to=${outputDir} --save-as=${tempName} --theme dracula`);
    break;
  }catch (e){
    console.log('retrying snippet ...' )
  }
  }

  if (!fs.existsSync(outputFilePath)) {
    throw new Error(`Snippet generation failed for: ${cppFilePath}`);
  }

  return outputFilePath;
};
const addFirstPageWithTextAndLink = async (pdfDoc: PDFDocument) => {
  const firstPage = pdfDoc.addPage([595.28, 841.89]); // A4 size (portrait)

  const font = await pdfDoc.embedFont(StandardFonts.Helvetica);
  const fontSize = 16;
  const cyanColor = rgb(0, 1, 1);

 
  const textLines = [
    "اسئلة امتحانات نهائية سابقة للأستاذ فرج الشركسي",
    "",
    "في اسئلة مكررة ف الملف وفي اسئلة فيها اختلاف بسيط لو شفت سوال متكرر ركز فيه مرات فيه اختلاف بسيط",
    "",
    "النص الاول اسئلة مقالية و الباقي تتبع",
    "",
    "لو لاحظتو أي خطأ قولولنا",
  ];

  let y = 700; 

  for (const line of textLines) {
    const textWidth = font.widthOfTextAtSize(line, fontSize);
    const x = (595.28 - textWidth) / 2;
    firstPage.drawText(line, {
      x,
      y,
      size: fontSize,
      font,
      color: rgb(1, 1, 1),
    });
    y -= fontSize + 10;
  }


  const linkText = "لو اي حد بيي الاكواد يفهمهم يضغط هنا";
  const linkFontSize = 14;
  const linkWidth = font.widthOfTextAtSize(linkText, linkFontSize);
  const linkX = (595.28 - linkWidth) / 2; 
  const linkY = y - 20; 

  
  firstPage.drawText(linkText, {
    x: linkX,
    y: linkY,
    size: linkFontSize,
    font,
    color: cyanColor, 
  });


  firstPage.node.set(
    //@ts-ignore d
    'Annots',
    pdfDoc.context.obj([
      pdfDoc.context.obj({
        Type: 'Annot',
        Subtype: 'Link',
        Rect: [linkX, linkY, linkX + linkWidth, linkY + linkFontSize],
        Border: [0, 0, 0], 
        A: {
          Type: 'Action',
          S: 'URI',
          URI: "https://github.com/AminAbbar/exams-overdose", 
        },
      }),
    ])
  );
};



const generatePdf = async (pdfDoc: PDFDocument, questionImagePath: string, codeSnippetImagePath: string) => {
  const questionImageBytes = fs.readFileSync(questionImagePath);
  const codeSnippetImageBytes = fs.readFileSync(codeSnippetImagePath);

  const page = pdfDoc.addPage();
  const questionImage = await pdfDoc.embedPng(questionImageBytes);
  const codeSnippetImage = await pdfDoc.embedPng(codeSnippetImageBytes);

  const questionDims = questionImage.scale(1);
  let codeSnippetDims = codeSnippetImage.scale(0.4);

  const desiredAspectRatio = 1.5;

  const maxCodeWidth = codeSnippetDims.height * desiredAspectRatio;

  if (codeSnippetDims.width > maxCodeWidth) {
    const scaleFactor = maxCodeWidth / codeSnippetDims.width;
    codeSnippetDims = codeSnippetImage.scale(scaleFactor);
  }

  const pageWidth = Math.max(questionDims.width, codeSnippetDims.width);
  const pageHeight = questionDims.height + codeSnippetDims.height;
  page.setSize(pageWidth, pageHeight);

  page.drawRectangle({
    x: 0,
    y: 0,
    width: pageWidth,
    height: pageHeight,
    color: rgb(0, 0, 0), 
  });

 
  const questionX = (pageWidth - questionDims.width) / 2;
  const codeSnippetX = (pageWidth - codeSnippetDims.width) / 2; 


  page.drawImage(questionImage, {
    x: questionX,
    y: codeSnippetDims.height, 
    width: questionDims.width,
    height: questionDims.height,
  });

  page.drawImage(codeSnippetImage, {
    x: codeSnippetX,
    y: 0, 
    width: codeSnippetDims.width,
    height: codeSnippetDims.height,
  });
};

const generateSubjectPdfs = async () => {
  const subjects = getFolderContent(path.join(dirname as string, ".."));

  for (const subject of subjects) {
    if(subject.name == 'GI131' )continue;
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
  if(traceFiles.length > 0 && false) {
  const templateBytes = fs.readFileSync(path.join(import.meta.dirname as string , `تتبع ${period == "mid" ? 'النصفي' : 'النهائي'}.pdf`))
  const tracePDF = await PDFDocument.load(templateBytes);
  const tracPDFPath = path.join(subjectPath, period, `تتبع ${period == "mid" ? 'النصفي' : 'النهائي'}.pdf`);

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
  const templateBytes = fs.readFileSync(path.join(import.meta.dirname as string , `مقالي ${period == "mid" ? 'النصفي' : 'النهائي'}.pdf`))
  const problemSolvingPDF =  await PDFDocument.load(templateBytes)
  const problemSolvingPDFPath = path.join(subjectPath,  period, `مقالي ${period == "mid" ? 'النصفي' : 'النهائي'}.pdf`);
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
