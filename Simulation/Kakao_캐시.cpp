/*
오답노트
1. 캐시에 존재할 경우 그냥 시간만 더해주는 게 아니라
  캐시에서 지운 후에 맨 마지막으로 넣어줘야 함
*/
def f2(x):
    return x[1]

def solution(cacheSize, cities):
    answer = 0
    cache = [] # 0번째가 가장 오래된 것
    time = 0
    for target in cities:
        target = target.lower()
        if target in cache:
            answer += 1
            cache.remove(target)
            cache.append(target)
        else:
            answer+=5
            # 캐시에 자리 있는 경우
            if(len(cache)<cacheSize):
                cache.append(target)
            # 없는 경우
            else:
                if len(cache):
                    del cache[0]
                    cache.append(target)
        time += 1
    return answer
