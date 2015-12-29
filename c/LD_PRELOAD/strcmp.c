/**
 * A patched version of strcmp that always interprets s1 and s2 at matching.
 * To be used with LD_PRELOAD and LD_LIBRARY_PATH.
 */

int strcmp(const char *s1, const char *s2) {
    return 0;
}
