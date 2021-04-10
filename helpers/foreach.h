#if __cplusplus >= 201103L
    #define foreach(i, stl) for (i : stl)
#else
    #define foreach(i, stl) for (typeof(stl.begin()) it = stl.begin(); it != stl.end(); ++it)\
                            switch (i = *it)\
                            default:
#endif
