// Room: /u/w/wangs/a/yu54.c

inherit ROOM;

void create()
{
	set("short", "÷��С·");
	set("long", @LONG
����������÷������ɫ��ǳһ���һ����ٴ�˿������״��
�������ˣ�����ʹ������÷�����Կຮ�����ľ��䣬����
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu53",
  "northeast" : __DIR__"yu55",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
