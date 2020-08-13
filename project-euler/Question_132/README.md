# 오일러 프로젝트 - 131번 문제 ( 매우 큰 레퓨닛의 인수 )

* 문제
<pre>
<code>
모든 자리수가 1로 이루어진 숫자를 레퓨닛(repunit)이라고 부릅니다. k자리의 레퓨닛을 R(k)라 하겠습니다.

예를 들어, R(10) = 1111111111 = 11 x 41 x 271 x 9091 이고, 이들 소수 인수의 총합은 9414입니다.

R(109)의 처음 40개 소수 인수의 합은 얼마입니까?
</code>
</pre>

* 풀이

자 두번째 문제입니다! 레퓨닛이라는 수를 활용한 문제군요! 표본을 구하는 것은 어렵지 않아 보입니다. 일단 그러면 R(1)부터 R(10)까지의 레퓨닛 수를 구해보죠

<pre>
<code>
function R (n) {
	let str = "";
	for(let i = 0; i < n; i++) {
		str += "1"
	}
	return Number(str);
}

let repunits = [];
for(let i = 1; i <= 5; i++) {
	repunits.push(R(10**i));
}

console.log(repunits)
</code>
</pre>

문자열로 1을 붙인 뒤 Number 생성자로 숫자형으로 바꿔주었습니다

한번 소인수분해도 해볼까요? library에 등록된 factorization.js 의 함수를 이용하겠습니다.

<pre><code>
// Factorization

function factorization (num) {
	
	let arr = [], i;
	if (num==1) return [1];

	for (i = 2; i != num; i++) {
		
		if(num%i==0){

			arr.push(i)
			num /= i--;

		}

	}

	arr.push(i)

	return arr
}
let factors = repunits.map(item=>{
	return factorization(item);
})
</code></pre>