#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(){
    fs::path folder = "C:\\Users\\alija\\Downloads";
    fs::path imagesFolder = folder / "Images";
    fs::path textFolder = folder / "TextFiles";
    fs::path documentsFolder = folder / "Documents";
    fs::path videosFolder = folder / "Videos";
    fs::path musicFolder = folder / "Music";
    fs::path archivesFolder = folder / "Archives";
    fs::path installersFolder = folder / "Installers";
    fs::path scriptsFolder = folder / "Scripts/Codes";

    // Creating the folders if they dont exist
    if(!fs::exists(imagesFolder)){
        fs::create_directory(imagesFolder);

        std::cout << "Created Images folder succesfully." << '\n';
    }
    if(!fs::exists(textFolder)){
        fs::create_directory(textFolder);

        std::cout << "Created Text folder succesfully." << '\n';
    }
    if(!fs::exists(documentsFolder)){
        fs::create_directory(documentsFolder);

        std::cout << "Created Document folder succesfully." << '\n';
    }
    if(!fs::exists(videosFolder)){
        fs::create_directory(videosFolder);

        std::cout << "Created Videos folder succesfully." << '\n';
    }
    if(!fs::exists(archivesFolder)){
        fs::create_directory(archivesFolder);

        std::cout << "Created Archives folder succesfully." << '\n';
    }
    if(!fs::exists(installersFolder)){
        fs::create_directory(installersFolder);

        std::cout << "Created Installers folder succesfully." << '\n';
    }
    if(!fs::exists(scriptsFolder)){
        fs::create_directory(scriptsFolder);

        std::cout << "Created Scripts folder succesfully." << '\n';
    }

    // moving the files into their appropriate folder
    for(auto &entry : fs::directory_iterator(folder)){
        if(!entry.is_regular_file()) continue;

        std::string ext = entry.path().extension().string();
        // making the extension lower case
        for (char& c : ext) {
        c = std::tolower(static_cast<unsigned char>(c));
        }

        fs::path oldPath;   
        fs::path newPath;
        // Images .png, .jpg
        if(ext == ".png" || ext == ".jpg"){

            oldPath = entry.path();
            newPath = imagesFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << imagesFolder << '\n';
        }

        // text files .txt, .md
        else if(ext == ".txt" || ext == ".md"){
             oldPath = entry.path();
             newPath = textFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << textFolder<< '\n';
        }

        // documents .pdf, .doc, .docx, .ppt, .pptx
        else if(ext == ".pdf" || ext == ".doc" || ext == ".docx" || ext == ".ppt" || ext == ".pptx"){
             oldPath = entry.path();
             newPath = documentsFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << documentsFolder<< '\n';
        }

        // videos .mp4
        else if(ext == ".mp4"){
             oldPath = entry.path();
             newPath = videosFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << videosFolder<< '\n';
        }

        // music / audios .mp3, .wav, .flac
        else if(ext == ".mp3" || ext == ".wav" || ext == ".flac"){
             oldPath = entry.path();
             newPath = musicFolder/ oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << musicFolder<< '\n';
        }

        // Archives / Compressed .zip, .rar, .7z, .tar, .gz
        else if(ext == ".zip" || ext == ".rar" || ext == ".7z" || ext == ".tar" || ext == ".gz"){
             oldPath = entry.path();
             newPath = archivesFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << archivesFolder<< '\n';
        }

        // Installers / executables .exe, .msi, .bat, .sh, .apk
        else if(ext == ".exe" || ext == ".msi" || ext == ".bat" || ext == ".sh" || ext == ".apk"){
             oldPath = entry.path();
             newPath = installersFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << installersFolder<< '\n';
        }

        // Code / Scripts .cpp, .h, .py, .js, .java, .c, .sql
        else if(ext == ".cpp" || ext == ".h" || ext == ".py" || ext == ".js" || ext == ".java" || ext == ".c" || ext == ".sql"){
             oldPath = entry.path();
             newPath = scriptsFolder / oldPath.filename();

            fs::rename(oldPath, newPath);
            std::cout << "Moved " << oldPath.filename() << " to " << scriptsFolder<< '\n';
        }
    }

        

    return 0;
}