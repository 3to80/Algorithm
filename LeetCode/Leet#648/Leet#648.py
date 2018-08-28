from collections import defaultdict


class Solution:

    def transform(self, word, problem):
        #brute version
        for i in range(len(word)):
            # dict에 word[:i]를 찾는다.
            target = word[:i]
            for dict_word in problem:
                if dict_word == target:
                    return dict_word

        return word

    def makeDict(self, problem):
        new_dict = {}
        for word in problem:
            i = 0
            target = new_dict
            while i < len(word):
                if not target.get(word[i]):
                    target.update({word[i]: {}})
                target = target.get(word[i])
                i += 1
        return new_dict




    def transform2(self, word, newdict):
        # word를 trie에 넣었을 때
        ret = str()
        section = newdict
        print(newdict)

        for l in range(len(word)):
            print(word, section)
            if section.get(word[l]):
                ret += word[l]
                section = section.get(word[l])
            elif isinstance(section.get(word[l]), dict):
                ret += word[l]
                return ret
            else:
                return word
        return word




    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        newdict = self.makeDict(dict)
        words = sentence.split(' ')
        out = self.transform2(words[0], newdict)
        for i in range(1, len(words)):
            out += ' ' + self.transform2(words[i], newdict)

        return out


if __name__ == '__main__':
    s = Solution()
    problem = ["a", "aa", "aaa", "aaaa", "rat"]
    # print(s.makeDict(dict))
    sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
    print(s.replaceWords(problem, sentence))



