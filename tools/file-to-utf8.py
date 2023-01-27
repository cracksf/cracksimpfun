import os
import chardet

def convert_encoding(root_path):
    for dirpath, dirnames, filenames in os.walk(root_path):
        for filename in filenames:
            if ".h" in filename or ".hpp" in filename or ".c" in filename or ".cpp" in filename:
                file_path = os.path.join(dirpath, filename)
                with open(file_path, 'rb') as f:
                    result = chardet.detect(f.read())
                    encoding = result['encoding']
                    if encoding != 'utf-8':
                        print(f"Converting {file_path} from {encoding} to utf-8")
                        with open(file_path, 'r', encoding=encoding) as f:
                            content = f.read()
                        with open(file_path, 'w', encoding='utf-8') as f:
                            f.write(content)

convert_encoding(".")
