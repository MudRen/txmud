// Room: /u/w/wangs/a/yu9.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu10",
  "west" : __DIR__"yu7",
]));
       set("outdoors","feiyu");

	setup();
}
