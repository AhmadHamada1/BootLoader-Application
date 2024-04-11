def transform_text_from_file(file_name):
    transformed_lines = []
    with open(file_name, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                transformed_lines.append('"{}"'.format(line))
    return ',\n'.join(transformed_lines)

# Example file name
file_name = r"D:\IMT WORK\Bootloader Application\OS.txt"

# Transform the text from the file
transformed_text = transform_text_from_file(file_name)

# Write the transformed text to a header file
header_content = f'''#ifndef APP_H_
#define APP_H_

const u8 arr[2954][45] = {{
{transformed_text}
}};
#endif /* APP_H_ */'''

# Write to the header file
header_file_name = "app.h"
with open(header_file_name, 'w') as header_file:
    header_file.write(header_content)

print(f"Header file '{header_file_name}' generated successfully.")
