https://blog.encrypted.gg/921
https://github.com/encrypted-def/basic-algo-lecture


![picture 0](images/58c59706080c7d2121f317b59797b524f8b64959ace7e848fae17be098d89e31.png)  

![picture 2](images/f5002216d46b3e2bc83db289fb587789285693a4f3d6229d25440feae23cdd40.png)  


![picture 6](images/c0d792c9991bcab1e8c9f2261064fbf8960a37f26bdba5a31014aa1d0f5d8f62.png)  


![picture 3](images/c2f171e863bd082368c25762b90d53cb36e5314b8f36936677b982e925e55155.png)  


![picture 4](images/a59ce95ffc466c4c9e805b7b50d826df6b54e5c115dec1143beb96a2db9f56a2.png)  


![picture 5](images/41bf5935b5a4e5b0f6d94e58f2c7537b158ea53df9627b57cad617c796f093ff.png)  


![picture 7](images/e80c1c496f584f070139369752f361acd53bfe360d4c49763e08c1a234ad4d95.png)  


![picture 8](images/961ca941ef45122ade44c294acfcd2471be542af0fee35f64c66fcd1d60c51ee.png)  

![picture 12](images/ea8523b7ff69bbfac7d960b46d49a4b7c5533ed0e8be91f11c6d9c90ae5bf71e.png)  

참조자는 상수 안되고 NULL 안되고 값이 배열같은 변수여야 함.


![picture 9](images/337fd746ab894e837fdaa126249c5b602573083cb0eff437a7dabf6342d5e399.png)  


![picture 10](images/380a0ece06da52536bfaab9df33ee1d3a2924b3b52ab56c132947559046b89d5.png)  
벡터 두개를 복사하는 데 걸리는 시간 O(n)

![picture 11](images/a6a3292cf0d23a8242f6d8abf1f5eaf7c6692a72c493ae45e004949c16c78dcf.png)  
참조자를 사용하여 메모리 주소만 넘기기 때문에 O(1) 만 걸림


![picture 13](images/d12d4bcb557929f2a957b673f51b9aab1bdbb5967450d3cd54860f9db8795fd3.png)  


![picture 14](images/ac0edcafc8a608076d0194c3c63220796cd52ced7c57c05cb1332fc065f65406.png)  

문자열 입력받을 때 `cin` 은 공백에서 끊기 때문에, `getline` 사용할 것.

![picture 15](images/55294ffedb4df640b2cb6b2a149a05f0d45fbd67ce3522c57036e185d942ee41.png)  


![picture 16](images/3b4bc1e8a4d839f8af12866a96b7c271bf3afef4c6c7ddb1924f9f138591400d.png)  


![picture 17](images/1998edb06a7647e45bb1385876d575f317f577103ff0a1594d5dd55fee7f258b.png)  

전자는 c++ 이 아닌 c 의 입출력 스트림을 끊어버리는 것. 일반적으로 clang 은 c/c++ 동시에 사용할 수 있도록 되어 있기 때문에, 입출력 스트림이 동기화되어 있다. 따라서 c++ 에서 문자열 입력시, 매번 c와 싱크해주는 작업이 수반되므로 TC 입력 시, 시간초과 날 수 있다. 해당 명령어는 이런 스트림 동기화를 끊으므로, 실행 후에는 cout 만 사용할 것!  

후자는 출력 버퍼를 계속 열어두겠다는 뜻. 일반적으로 버퍼란 사용자의 인터페이스에 최적화된 환경으로 개행문자나 특정 조건 만족시 버퍼에 들어간 문자열을 모두 비우므로서 스트림에 전달되는 구조이지만, 채점 저지 사이트에서는 입력 따위 보일 필요도 없고 알 바가 아니기 때문에, 출력에만 신경쓴다. 그니깐, 출력   버퍼를 열어두므로서 초기 화를 매번하는 상황을 피하므로서 시간을 번다. 

![picture 18](images/312f79035ae5e0946b8c10b31cc436427318196d5be39a51406edf96c30dd4ee.png)  

줄바꿈과 출력 버퍼를 비워주는 행동이기 때문에,, 기껏 위에 실행한 명령어가 의미가 없어지게 된다. 



![picture 19](images/88c98005672afe44ea3b246b938800d9356c939944a6a5f6eff63cd58b87c2e8.png)  

배열 초기화 방법.  
첫번째는 음,, 0 혹은 -1 로 전달하지 않으면 오동작의 여지가 있음.
두번째는 for 을 통한 초기화으로 언제나 사용 가능 능지
세번째는 fill 함수를 이용한 방법으로 제일 쉽고 간편함.
그리고 전역에 배열 선언하면 자동으로 0 으로 초기화됨.

![picture 20](images/a150681fd8de98a74753c4813d94727ac02e4ffb23d0aac569efbcdc856dc4f4.png)  

stl vector 관한 일반적인 사항. 구현한 insert 및 erase 기능들이 만들어져 있다. 특히 = 연산자 사용시 deepcopy 이므로 원본에는 영향이 없다. 다만, 역시 O(N) 의 시간복잡도가 지연됨을 유의할 것. 

![picture 21](images/77d0c957faabaa8dab9f6e4d6895e99391fff8d858295a57285e2df1f9097239.png)  

![picture 22](images/93312ec007031d323953d688ec0232349148c1cd8017ffbe200d9e3537e8ebac.png)  


for 문을 직관적으로 사용하는 예시가 제시. 다만 위의 e에서 &을 붙이면 값을 변경할 수 있다.


![picture 23](images/78ada1831c177efbfdc9b159cdbc618b1ac50ef0cda09d53db3e36779976196a.png)  

야매 연결 리스트 외워두기!!

5
1 23 53 77 60

:colorscheme 


vv



