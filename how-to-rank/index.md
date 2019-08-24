## Codeup OJ Tier // 랭킹 산출 기준



- 용어 설명

  + '정확한 풀이' == 코드업 제출 결과가 '정확한 풀이'가 나온 경우

  + '틀린 제출' == 코드업 제출 결과가 '정확한 풀이' 이외의 결과가 나올 경우

    '잘못된 풀이', '실행 중 에러', '표현 에러' 등이 '틀린 제출'로 계산됩니다.

    

- AC Rank

  '정확한 풀이' 가 얼마나 나왔는지 분석하여 랭킹을 산출함.

  해당 기간 동안 같은 문제를 여러번 풀어 '정확한 풀이' 가 여러 차례 나온 것은 인정하지 않음.

  <br>'정확한 풀이' 가 나온 개수가 같을 경우, 덜 틀린 순서대로 순위를 부여합니다.

  만약 틀린 제출 수도 같을 경우, 해당 기간 동안 먼저 제출을 한 이용자부터 높은 순위를 부여합니다.

  <br>

  의도적인 랭킹 조작을 방지하기 위해, 해당 기간 동안 동일한 문제에 여러 번 제출해 나온 '정확한 풀이'는 랭킹 산출 시 무시됩니다.

  e.g) 1001번 문제를 연속해서 3번 제출해 맞았다면 랭킹 산출 시에는 한번 맞은걸로 계산됩니다.

  <br>

  데이터는 [ 순위, 이용자 ID, 정확한 풀이가 나온 문제 수 ] 순서대로 작성됩니다.

- Submit Rank

  해당 기간동안 얼마나 제출했는지 분석하여 랭킹을 산출함. <br>

  채점 결과에 따라 영향을 받지 않으며, 해당 기간동안 제출한 모든 기록은 유효합니다.

  <br>

  제출 횟수가 동일하다면, '정확한 풀이' 수가 높은 순서대로 순위를 부여합니다.

  만약 '정확한 풀이' 수도 동일하다면, 해당 기간 동안 먼저 제출을 한 이용자부터 높은 순위를 부여합니다.

  <br>

  데이터는 [ 순위, 이용자 ID, 제출한 문제 수 ] 순서대로 작성됩니다.

- Troll Rank

  해당 기간동안 틀린 제출 수가 얼마나 많은지 분석하여 랭킹을 산출함.

  <br>

  틀린 문제 수가 동일하다면, 해당 기간 동안 제출한 문제 수가 많은 순서대로 순위를 부여합니다.

  만약 해당 기간 동안 제출한 문제 수도 동일하다면, 해당 기간 동안 먼저 제출을 한 이용자부터 높은 순위를 부여합니다.

  <br>

  데이터는 [ 순위, 이용자 ID, 틀린 문제 수 ] 순서대로 작성됩니다.

- Problem Rank

  해당 기간동안 이용자들이 가장 많이 푼 문제 순서대로 랭킹을 산출함.

  제출 결과에 영향을 받지 아니하며, 각각의 문제가 몇 번이나 제출되었는지 계산합니다.

  <br>

  제출 횟수가 동일하다면, 문제 번호가 큰 순서대로 순위를 부여합니다.

  <br>

  데이터는 [ 순위, 문제 번호, 제출한 기록 수 ] 순서대로 작성됩니다.