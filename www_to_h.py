import os

input_dir = 'src/www'
output_dir = 'include/www_h'

for root, dirs, files in os.walk(input_dir):
    for file in files:
        in_filename = os.path.join(root, file)
        out_filename = os.path.join(output_dir, file + '.h')
        out_data = []
        with open(in_filename, 'rb') as fi:
            while 1:
                byte = fi.read(1)
                if not byte:
                    break
                out_data.append('0x{:02x}'.format(ord(byte)))

        if os.path.exists(out_filename):
            os.remove(out_filename)
            
        with open(out_filename, 'w') as fo:
            fo.write(', '.join(out_data))

        print(in_filename + " -> " + out_filename)


