#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define USAGE_ERR 2
#define PARSING_ERROR 1
#define SHOW_FULL_LISTS true

#define ASCII_ART_NEGATIVES "\
⡴⠒⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠉⠳⡆⠀ \n\
⣇⠰⠉⢙⡄⠀⠀⣴⠖⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠁⠙⡆ \n\
⠘⡇⢠⠞⠉⠙⣾⠃⢀⡼⠀⠀⠀⠀⠀⠀⠀⢀⣼⡀⠄⢷⣄⣀⠀⠀⠀⠀⠀⠀⠀⠰⠒⠲⡄⠀⣏⣆⣀⡍ \n\
⠀⢠⡏⠀⡤⠒⠃⠀⡜⠀⠀⠀⠀⠀⢀⣴⠾⠛⡁⠀⠀⢀⣈⡉⠙⠳⣤⡀⠀⠀⠀⠘⣆⠀⣇⡼⢋⠀⠀⢱ \n\
⠀⠘⣇⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⡴⢋⡣⠊⡩⠋⠀⠀⠀⠣⡉⠲⣄⠀⠙⢆⠀⠀⠀⣸⠀⢉⠀⢀⠿⠀⢸ \n\
⠀⠀⠸⡄⠀⠈⢳⣄⡇⠀⠀⢀⡞⠀⠈⠀⢀⣴⣾⣿⣿⣿⣿⣦⡀⠀⠀⠀⠈⢧⠀⠀⢳⣰⠁⠀⠀⠀⣠⠃ \n\
⠀⠀⠀⠘⢄⣀⣸⠃⠀⠀⠀⡸⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠈⣇⠀⠀⠙⢄⣀⠤⠚⠁⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⢘⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⢰⣿⣿⣿⡿⠛⠁⠀⠉⠛⢿⣿⣿⣿⣧⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡀⣸⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⡀⢀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠹⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⡿⠁⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣤⣞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣀⣠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠲⢤⣀⣀⠀⢀⣀⣀⠤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n\
segmentation fault (core dumped)\
"

#define ASCII_ART_NAN "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠖⠚⠉⠁⠀⠀⠀⠀⠀⠀⠉⠉⠒⠢⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡶⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠢⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⢀⡴⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢦⡀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢆⠀⠀⠀⠀⠀\n\
⠀⠀⠀⢠⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢳⡀⠀⠀⠀\n\
⠀⠀⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀\n\
⠀⢠⡏⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⢳⠀⠀\n\
⠀⡾⠀⠀⢰⣶⣾⣿⠟⠛⠉⠉⠉⠉⢉⠙⠛⢶⣤⣤⣤⣤⣤⣴⠾⠛⠋⠉⠉⠉⠉⠉⠛⠿⣿⣶⣦⡄⠀⠈⣇⠀\n\
⢰⠇⠀⠀⠈⢻⡿⠁⠀⠀⠀⠀⢀⡾⠋⢳⡀⠀⠹⣿⣿⣿⣿⠁⠀⣼⠋⠻⡄⠀⠀⠀⠀⠀⠘⣿⡏⠃⠀⠀⢻⠀\n\
⢸⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⢸⡇⠀⢸⡇⠀⢰⣿⠁⠙⣿⠀⠀⣏⠀⢠⣷⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⢸⡆\n\
⢸⠀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠀⠘⣧⣐⣾⠃⠀⣼⠇⠀⠐⢻⣆⠀⢿⣄⣿⡏⠀⠀⠀⠀⠀⢀⡿⠀⠀⠀⠀⢸⡇\n\
⢸⡄⠀⠀⠀⠀⠹⣧⡀⠀⠀⠀⠀⠈⠛⠁⢀⣼⠏⠀⠀⠀⠈⢻⣦⡈⠙⠉⠀⠀⠀⠀⠀⣠⣾⠃⠀⠀⠀⠀⣾⠀\n\
⠀⣇⠀⠀⠀⠀⠀⠈⠻⢷⣦⣤⣤⣤⣴⡾⠟⠁⠀⠀⠀⠀⠀⠀⠙⠻⢶⣤⣤⣤⣤⣴⠾⠟⠁⠀⠀⠀⠀⠀⡟⠀\n\
⠀⠸⡆⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⡆⠄⠀⠀⠀⠀⠀⠀⠀⠀⣼⠃⠀\n\
⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠻⣷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣾⠇⠀⠀⠀⠀⠀⠀⠀⠀⣰⠇⠀⠀\n\
⠀⠀⠀⢳⡄⠀⠀⠀⠀⠀⠀⠈⠻⢮⣙⡛⣶⠒⠒⠲⡖⠒⠒⢲⣞⣫⣽⠟⠃⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀\n\
⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢻⡄⠀⠀⡇⠀⢀⡾⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⠖⠓⠖⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠈⠛⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠶⢤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠒⠒⠒⠒⠒⠒⠒⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"

#define ASCII_ART_EMPTY "\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠛⠛⢉⢉⣉⣉⢉⣉⡉⠛⠛⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⣠⢴⣲⣞⡽⣯⠾⣜⣮⣛⡶⣭⣏⡷⣒⠦⡄⣈⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⡁⣴⣺⠝⠉⠈⠁⠉⠉⠉⠉⢿⣷⣿⣻⣷⣯⡟⠉⠁⠈⠈⠐⠂⠀⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⡿⢟⣉⠙⢿⣿⡿⠋⣠⣴⣻⡷⣿⣇⢀⣀⣠⣤⣤⣶⣶⣿⡿⣿⣽⣷⣻⣿⢶⣤⣤⣀⣀⠀⣰⢣⡄⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⠏⣤⣄⠈⢋⣴⣿⡿⠁⣸⠟⢀⣶⢯⣷⣿⣿⣿⣿⣿⡿⢿⡻⣽⢳⡯⣷⣟⣯⡿⣿⣳⣟⢯⡞⡵⠫⠝⣯⢳⡏⣾⡡⠌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⠀⣿⠟⠀⢸⣷⡌⠀⢐⣩⣤⡙⠻⣿⣿⣿⣿⣻⡟⢧⣛⢶⣳⢮⣗⣞⣦⠙⢞⣿⣟⠿⣼⢣⣟⣴⣃⠖⠀⠉⠚⠥⡻⠵⠗⠊⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⠀⣿⡷⠀⢸⣍⢠⠘⠿⠇⢿⣿⡷⠈⠿⠿⠟⠃⠉⠁⠀⠀⠀⠀⠀⠉⠘⠋⠌⢺⡯⣽⠾⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣆⢻⣤⡄⠘⠏⠘⠃⢀⣀⡄⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣾⣷⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⡏⣰⣿⡷⠀⠀⠀⢀⡈⠟⣁⣾⡿⠀⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⣿⡇⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⢁⣿⣿⣏⠀⠀⠀⣿⣿⣷⣿⠟⢁⣼⣿⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣿⣷⣿⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⡏⢸⣿⣿⠇⠀⣾⠀⠻⠿⠟⣁⣴⣿⣿⣿⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢼⣚⢿⣿⣷⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⡀⢤⣙⠉⠀⠀⣡⣴⠀⠲⣝⣻⡿⣿⡽⣯⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠐⠏⣻⢾⡭⠛⣾⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣶⣤⣥⣤⣤⣿⣿⠄⠘⣬⢳⣻⢵⠋⠉⠉⠉⢛⠋⠛⠷⠲⠶⣔⣶⣚⣛⡛⢟⣛⣻⡛⢏⠛⠙⠫⠑⢀⠀⠀⢀⢤⣤⡉⣿⠆⢀⣿⣿⣿⣿⣿⣿⣿⠟⠛⠻⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⢎⡱⣏⡾⣷⣿⣿⣶⣈⠻⠈⣷⣶⠐⣶⣶⣆⢰⣶⣶⠀⣶⣶⡆⢰⣶⠇⠸⠋⠀⣠⣟⡳⣞⡽⣹⠀⣸⣿⣿⣿⣿⣿⣿⡏⢰⣿⡆⢹⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠸⣝⡾⣽⣿⣽⡿⣿⣷⣤⡰⢮⢠⣭⣭⡍⣨⣭⣥⢀⣬⣥⡄⢴⣶⡆⢸⢋⣼⠓⢨⢷⣙⠾⠁⢠⣿⣿⣿⣿⣿⣿⣿⡇⢰⣶⡆⣾⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠁⢾⣹⢳⣯⣿⣻⣽⡞⢷⣿⣦⣍⠻⠿⣧⣿⣿⣿⠠⣿⣿⡇⡾⠟⢃⣴⠫⠂⣰⡛⣦⢋⠞⢠⣿⣿⣿⣿⣿⣿⣿⣿⠀⢼⣯⣄⢻⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠈⢞⡭⣟⡾⣯⢿⣽⣆⡘⠛⣿⣿⣶⣦⣤⣭⣍⣤⣩⣥⣤⡖⣯⡛⠂⣠⡞⢧⡙⡄⠃⣠⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠈⣉⣠⣉⣋⠛⢿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠙⢮⢳⡽⣻⣞⣿⣻⣷⣤⣈⠛⠳⠿⢟⡾⢷⡟⠞⠖⠙⣀⠴⡚⡵⢊⠇⠈⣀⣾⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠨⠀⠀⣽⣿⣿⣿⣿⡆⣹\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠁⡳⣓⢮⢳⡳⢮⡳⣏⣟⡳⢖⢦⡒⢦⡔⡲⢜⡹⢌⡣⠝⠐⠉⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⠆⠐⠀⡀⢠⣄⣠⣄⣀⠰⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣈⠈⠣⢙⢣⠳⡍⠶⣙⠞⢦⡙⢦⠓⡍⠎⠐⠃⢀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⠀⠀⢄⠈⢻⣿⣿⣿⣿⣿⣸\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣤⣌⣁⣈⣈⣀⣁⣀⣤⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⢠⣦⣦⣭⣤⡹⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⡘⠿⠿⠿⠿⢃⣿⣿\n\
"
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
	public:
		long getElapsedTime() const;
		PmergeMe(std::vector<size_t> &numbers);

		template<typename T> T fordJohnson(T data)
		{
			gettimeofday(&start_time, NULL);
			T indices;
			T sortedData;

			for (size_t i = 0; i < data.size(); i++)
				indices.push_back(i);


			indices = pairAndSplit(data, indices);

			for (size_t i = 0; i < indices.size(); i++)
				sortedData.push_back(data[indices[i]]);


			gettimeofday(&end_time, NULL);
			return indices;

		}
		template<typename T> static void printVec(T &v)
		{
			std::cout << "[";
			for (typename T::iterator it = v.begin(); it != v.end(); ++it)
			{
				if (SHOW_FULL_LISTS || v.size() < 10 || std::distance(v.begin(), it) < 3 || std::distance(v.begin(), it) >= std::distance(v.begin(), v.end() - 3))
				{
					std::cout << *it;
					if (it + 1 != v.end())
						std::cout << ";";
				}
				else if (v.size() >= 10)
				{
					if (std::distance(v.begin(), it) == 5)
						std::cout << "...;";
				}
			}
			std::cout << "]" << std::endl;
		}

		template<typename T> static void printVec(T &v, T &data)
		{
			std::cout << "[";
			for (typename T::iterator it = v.begin(); it != v.end(); ++it)
			{
				std::cout << data[*it];
				if (it + 1 != v.end())
					std::cout << ";";
			}
			std::cout << "]" << std::endl;
		}

	private:
		timeval start_time;
		timeval end_time;
		std::vector<size_t> numbers_vector;
		std::deque<size_t> numbers_deque;
		PmergeMe();
		PmergeMe(PmergeMe &other);

		template <typename T> struct CompareByValue
		{
			const T& seq;
			CompareByValue(const T& s) : seq(s) {}
			bool operator()(std::size_t a, std::size_t b) const {
				return seq[a] < seq[b];
			}
		};

		/**
		 * @brief creates a jacobsthal insertion sequence for a given range.
		 * @param range the size of the losing chain (max index of element to be inserted)
		 * @returns a vector of indexes to be inserted in JacobSthal order.
		 */
		template<typename T> T createJacobSthalSequence(size_t n)
		{
			T jacob;
			T seq;

			/* First, generate the Jacobsthal numbers up to n. */

			if (n <= 1)
				return seq;

			jacob.push_back(1);
			jacob.push_back(3);

			while (jacob.back() < n - 1)
				jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

			/* Then, generate the Jacobsthal insertion sequence. */

			size_t	prev = 0;

			for (size_t i = 0; i < jacob.size(); ++i)
			{
				size_t	hi = std::min(jacob[i], n - 1);
				for (size_t j = hi; j > prev; --j)
					seq.push_back(j);
				if (hi >= n - 1)
					break;
				prev = jacob[i];
			}
			return (seq);
		}

		template<typename T> T pairAndSplit(const T &data, T indices)
		{
			if (indices.size() == 1)
				return (indices);

			T	winChain;
			T	loseChain;

			size_t	straggler = 0;
			bool hasStraggler = indices.size() % 2 != 0;

			if (hasStraggler)
			{
				straggler = indices.back();
				indices.pop_back();
			}

			for (size_t i = 0; i < indices.size() - 1; i +=2)
			{
				if (data[indices[i]] < data[indices[i+1]])
				{
					winChain.push_back(indices[i + 1]);
					loseChain.push_back(indices[i]);
				}
				else
				{
					winChain.push_back(indices[i]);
					loseChain.push_back(indices[i + 1]);
				}
			}

			T partnerLoser(data.size());

			/* Maintain the loser/winner bond by representing it by value (index in data, not position in the chain) */

			for (size_t i = 0; i < winChain.size(); ++i)
				partnerLoser[winChain[i]] = loseChain[i];

			T newWinChain = pairAndSplit(data, winChain);

			T orderedLosers(loseChain.size());

			for (size_t i = 0; i < loseChain.size(); ++i)
				orderedLosers[i] = partnerLoser[newWinChain[i]];

			newWinChain.insert(newWinChain.begin(), orderedLosers[0]);

			T jacobSthalSeq = createJacobSthalSequence<T>(orderedLosers.size()); // 0, 1, 3, 2, 5, 4 etc

			T winnerPositions;
				
			for(typename T::iterator loser = orderedLosers.begin(); loser != orderedLosers.end(); ++loser)
				winnerPositions.push_back(std::distance(orderedLosers.begin(), loser) + 1);

			for (typename T::iterator currentLoserIndex = jacobSthalSeq.begin(); currentLoserIndex != jacobSthalSeq.end(); ++currentLoserIndex)
			{

				size_t element = orderedLosers[*currentLoserIndex];
				
				typename T::iterator low = newWinChain.begin();
				typename T::iterator high = newWinChain.begin() + winnerPositions[*currentLoserIndex];

				CompareByValue<T> comp(data);
				typename T::iterator insertPos = std::upper_bound(low, high, element, comp);
		
				size_t insertedIndex = std::distance(newWinChain.begin(), insertPos);
				newWinChain.insert(insertPos, element);

				for (size_t k = 0; k < winnerPositions.size(); ++k)
				{
					if (winnerPositions[k] >= insertedIndex)
						++winnerPositions[k];
				}
			}

			if (hasStraggler)
			{
				CompareByValue<T> comp(data);
				typename T::iterator insertPos = std::upper_bound(newWinChain.begin(), newWinChain.end(), straggler, comp);
				newWinChain.insert(insertPos, straggler);
			}
			return (newWinChain);
		}
	};

#endif
