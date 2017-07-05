설치 후 별다른 설정을 해주지 않으면 CATALINA_HOME과 CATALINA_BASE는 동일하다.

CATALINA_HOME 하위 디렉토리
	bin - startup.sh, shutdown.sh
		- setenv.sh, tomcat-juli.jar
	lib - lib and class

CATALINA_BASE 하위 디렉토리
	bin
	conf - 서버 설정 파일 (server.xml)
	lib - lib and class
	logs - 로그, 출력 파일
	webapps - 웹앱 위치
	work - 웹앱의 임시 작업공간
	temp - 임시파일을 사용하는 jvm의 작업공간

lib은 서로 공유하고 있더라도 CATALINA_BASE의 라이브러리와 클래스가 우선된다.
표준 tomcat 라이브러리를 CATALINA_HOME에 추가하고 데이터베이스 드라이버 같은 추가 라이브러리를 CATALINA_BASE에 추가할 수 있다.
