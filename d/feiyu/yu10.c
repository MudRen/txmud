// Room: /u/w/wangs/a/yu10.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ����������ƺ���
һ����ª��СԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"yu13",
  "northwest" : __DIR__"yu9",
  "east" : __DIR__"yu11",
]));
       set("outdoors","feiyu");

	setup();
}
