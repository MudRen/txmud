// Room: /u/w/wangs/a/yu6.c

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
  "west" : __DIR__"yu5",
  "east" : __DIR__"yu7",
]));
       set("outdoors","feiyu");

	setup();
}
