import { execSync } from "node:child_process"
import { writeFileSync } from "node:fs";
import puppeteer from "npm:puppeteer";
import { join, basename } from "@std/path";

const generateCodeSnippet = (cppFilePath: string, outputDir: string): string => {
  const fileNameWithoutExt = basename(cppFilePath, ".cpp");
  const outputFilePath = join(outputDir, `${fileNameWithoutExt}.png`);

  execSync(`carbon-now ${cppFilePath} --save-to=${outputDir} --save-as=${fileNameWithoutExt} --theme dracula`);

  if (!Deno.statSync(outputFilePath).isFile) {
    throw new Error(`Snippet generation failed for: ${cppFilePath}`);
  }

  return outputFilePath;
};

const generateHtmlFile = async (htmlFilePath: string, questionImagePath: string, codeSnippetImagePath: string) => {
  const htmlContent = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Question and Solution</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                margin: 0;
                padding: 0;
            }
            .question {
                margin-bottom: 20px;
            }
            .solution {
                margin-top: 20px;
            }
            img {
                max-width: 100%;
                height: auto;
            }
        </style>
    </head>
    <body>
            <img src="../${questionImagePath}" alt="Question Image">
            <img src="../${codeSnippetImagePath}" alt="Code Snippet">
    </body>
    </html>
  `;

   writeFileSync(htmlFilePath, htmlContent);
  console.log(`HTML file generated at ${htmlFilePath}`);
};

const generatePdf = async (codeSnippetImagePath: string, outputPdfPath: string) => {

  console.log(`PDF generated at ${outputPdfPath}`);
};

const generateQuestionPdf = async ( questionImage: string, cppFile: string) => {

  const codeSnippetImage = generateCodeSnippet(cppFile, outputDir);

  await generatePdf(codeSnippetImage, questionImage);
};

const questionImagePath = "../GI132/examples/1.png"; 
const cppFilePath = "../GI132/examples/1.cpp";
const outputDir = "./";

await generateQuestionPdf( questionImagePath, cppFilePath);
