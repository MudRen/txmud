// Room: /u/w/wangs/a/yu13.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ�����������һ��
�����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu14",
  "northwest" : __DIR__"yu10",
]));

	set("outdoors","feiyu");

	setup();
}
