#include <argp.h>

#include <deque>
#include <iostream>
#include <string>

#include "btree.hpp"
#include "loader.hpp"

const char doc[] = "A simple example of binary search trees.";
const char args_doc[] = "PATH_OF_INPUT_TXT";

static struct argp_option options[] = {
    {"output", 'o', "FILE", 0, "Output to FILE instead of standard output"},
    {0},
};

struct arguments {
    char *args[1];
    std::string output_file;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *)state->input;

    switch (key) {
        case 'o':
            arguments->output_file = arg;
            break;

        case ARGP_KEY_ARG:
            if (state->arg_num > 1) /* Too many args */
                /* Ignore unnecessary */
                argp_usage(state);
            arguments->args[state->arg_num] = arg;
            break;

        case ARGP_KEY_END:
            if (state->arg_num < 1) /* Not enough args */
                /* Fail and quit */
                argp_usage(state);
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

// Actual CLI parser
static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv) {
    FILE *fp;

    struct arguments arguments;
    // Default arguments
    arguments.output_file = "";

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    //  Create the output file if necessary
    if (arguments.output_file.empty())
        fp = stdout;
    else
        fp = fopen(arguments.output_file.c_str(), "w");

    // Grab data from txt file
    BTree<int> btree = load(arguments.args[0]);
    // Dump to deque
    std::deque<int> sorted_data = btree.dump();

    // Write data to output
    for (int i : sorted_data) {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);

    return 0;
}
