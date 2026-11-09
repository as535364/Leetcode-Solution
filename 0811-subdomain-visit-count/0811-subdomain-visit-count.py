class Solution:
    def subdomainVisits(self, cpdomains: list[str]) -> list[str]:
        counts = defaultdict(int)
        for cpdomain in cpdomains:
            count, domain = cpdomain.split()
            domain_split = domain.split('.')
            count = int(count)

            for i in range(len(domain_split)):
                domain_suffix = '.'.join(domain_split[i:])
                counts[domain_suffix] += count
        
        return [f"{v} {k}" for k, v in counts.items()]
