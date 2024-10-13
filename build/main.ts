import * as path from "@std/path";
const encoder = new TextEncoder();
const decoder = new TextDecoder();
const metaData: Record<string, string> = JSON.parse(decoder.decode(Deno.readFileSync("./metadata.json")));
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

const readFileContent = (filePath: string) => {
  const fileContent = Deno.readFileSync(filePath);
  return decoder.decode(fileContent);
};

const generateCppFileContent = (dir: string, subjectName: string, period: string) => {
    const files = getFolderContent(dir, false).filter(file => file.name.endsWith(".cpp"));
    let cppContent = '';
  
    for (const file of files) {
      const fileNameWithoutExt = file.name.replace('.cpp', '');
      const relativeImagePath = `./${subjectName}/${period}/${path.basename(dir)}/${fileNameWithoutExt}.png`;
      const cppFilePath = path.join(dir, file.name);
  
      if (Deno.statSync(path.join(dir, `${fileNameWithoutExt}.png`)).isFile) {
        cppContent =cppContent.trim() + `\n![](${relativeImagePath}) \n`;
      }
  
      cppContent += '\n ```cpp \n' + `${readFileContent(cppFilePath)} ` + " \n```";
    }
  
    return cppContent;
  };
const generateSectionContent = (id: string, hasMid: boolean, hasFinal: boolean) => {
  let sectionContent = '';
  const currentFolder = getFolderContent(path.join(dirname as string, "..")).find(subject => subject.name == id);
  if (!currentFolder) throw new Error("subject folder not found");

  if (hasMid) {
    const traceDir = path.join(dirname as string, "..", currentFolder.name, 'mid', "tracing");
    const problemSolvingDir = path.join(dirname as string, "..", currentFolder.name, 'mid', "problemSolving");

    sectionContent += `
      <br id="${id}_mid_Trace">
      <details><summary><h3> نصفي - أسئلة التتبع :</h3></summary>
${generateCppFileContent(traceDir,currentFolder.name,"mid")}
</details>
      <br id="${id}_mid_Problem">
      <summary><h3> نصفي - الأسئلة المقالية :</h3></summary>
${generateCppFileContent(problemSolvingDir,currentFolder.name,"mid")}
    `;
  }

  if (hasFinal) {
    const traceDir = path.join(dirname as string, "..", currentFolder.name, 'final', "tracing");
    const problemSolvingDir = path.join(dirname as string, "..", currentFolder.name, 'final', "problemSolving");

    sectionContent += `
      <br id="${id}_final_Trace">
<details>      <summary><h3>نهائي - أسئلة التتبع :</h3></summary>

${generateCppFileContent(traceDir , currentFolder.name,"final")}
</details>
<br id="${id}_final_Problem">
<details>      <summary><h3>نهائي - الأسئلة المقالية :</h3></summary>
      
${generateCppFileContent(problemSolvingDir,currentFolder.name,"final")}
</details>
    `;
  }

  return sectionContent;
};

const generateSubjectSection = (subjectName: string, hasMid: boolean, hasFinal: boolean) => {
  const id = subjectName.trim();
  const displayName = metaData[id] || subjectName;

  const sectionHTML = `<br id="${id}" />
    <details>
      <summary><h1>${displayName}</h1></summary>
      ${hasFinal && hasMid ? '<h3>الفترة</h3>' : ''}
      <ul>
        ${hasMid ? `
          <li>
            <summary><b>أسئلة النصفي</b></summary>
            <ol>
              <li><summary><a href="#${id}_mid_Trace"><b>أسئلة التتبع</b></a></summary></li>
              <li><summary><a href="#${id}_mid_Problem"><b>أسئلة المقالي</b></a></summary></li>
            </ol>
          </li>` : ''}
        ${hasFinal ? `
          <li>
            <summary><b>أسئلة النهائي</b></summary>
            <ol>
              <li><summary><a href="#${id}_final_Trace"><b>أسئلة التتبع</b></a></summary></li>
              <li><summary><a href="#${id}_final_Problem"><b>أسئلة المقالي</b></a></summary></li>
            </ol>
         </li>` : ''}
      </ul>`.replace(/\n/g, '')+` ${generateSectionContent(id, hasMid, hasFinal)}
</details>
  `;

  return sectionHTML;
};

const buildReadmeContent = () => {
  let readmeContent = `<div align="center">
    <h3 align="center">أسئلة امتحانات نهائية سابقة مع الحل</h3>
    <p align="center">
      لو عندك اسئلة زيادة او لاحظت خطأ تقدر تصلحه مباشرة او قوللنا ويتصلح
      <br />
      <a href="https://t.me/yourSpaece">قناة التلغرام</a>
      ·
      <a href="https://t.me/itstudents2024">قروب التلغرام</a>
    </p>
  </div>`;

  const subjectsHTML = [];
  const sectionsHTML = [];

  for (const subject of getFolderContent(path.join(dirname as string, ".."))) {
    const subjectPath = path.join(dirname as string, "..", subject.name);
    const files = Array.from(Deno.readDirSync(subjectPath));

    const hasMid = hasFolder(files, "mid");
    const hasFinal = hasFolder(files, "final");

    const displayName = metaData[subject.name.trim()] || subject.name;
    const id = subject.name.trim();

    subjectsHTML.push(`<li><a href="#${id}"><h3><b>${displayName}</b></h3></a></li>`);
    sectionsHTML.push(generateSubjectSection(subject.name, hasMid, hasFinal));
  }

  readmeContent += `
    <h1>المواد :</h1>
    <ol>
      ${subjectsHTML.join("\n")}
    </ol>
    ${sectionsHTML.join("\n")}
  `;

  return readmeContent;
};

try {
  const readmeContent = buildReadmeContent();
  Deno.writeFileSync('../README.md', encoder.encode(readmeContent));



} catch (error) {
  console.error("error : ", error);
}
