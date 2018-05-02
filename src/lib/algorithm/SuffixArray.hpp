#define pushS(x) sa[cur[s[x]]--] = x
#define pushL(x) sa[cur[s[x]]++] = x
#define inducedSort(v) fill_n(sa, n, -1); fill_n(cnt, m, 0);                     \
    for (int i = 0; i < n; ++i) cnt[s[i]]++;                                     \
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];                            \
    for (int i = 0; i < m; ++i) cur[i] = cnt[i] - 1;                             \
    for (int i = n1 - 1; i >= 0; --i) pushS(v[i]);                               \
    for (int i = 1; i < m; ++i) cur[i] = cnt[i - 1];                             \
    for (int i = 0; i < n; ++i) if (sa[i] > 0 && t[sa[i] - 1]) pushL(sa[i] - 1); \
    for (int i = 0; i < m; ++i) cur[i] = cnt[i] - 1;                             \
    for (int i = n - 1; i >= 0; --i) if (sa[i] > 0 && !t[sa[i] - 1]) pushS(sa[i] - 1)

void sais(int n, int m, int *s, bool *t, int *p) {
    int n1 = 0, ch = rk[0] = -1, *s1 = s+n;
	t[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) t[i] = s[i] == s[i + 1] ? t[i + 1] : (s[i] > s[i + 1]);
    for (int i = 1; i < n; ++i) rk[i] = (t[i - 1] && !t[i]) ? (p[n1] = i, n1++) : -1;
    inducedSort(p);
    for (int i = 0, x, y; i < n; ++i) if ((x = rk[sa[i]]) != -1) {
        if (ch < 1 || p[x+1] - p[x] != p[y+1] - p[y]) ch++;
        else for (int j = p[x], k = p[y]; j <= p[x+1]; j++, k++)
            if ((s[j]<<1|t[j]) != (s[k]<<1|t[k])) {ch++; break;}
        s1[y = x] = ch;
    }
    if (ch+1 < n1) sais(n1, ch+1, s1, t+n, p+n1);
    else for (int i = 0; i < n1; ++i) sa[s1[i]] = i;
    for (int i = 0; i < n1; ++i) s1[i] = p[sa[i]];
    inducedSort(s1);
}