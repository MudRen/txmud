// Room: /wiz/louth/a/shan4.c

inherit ROOM;

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·�������Ƕ��͵����£������ϻ�����һ
ЩС���ݣ�ɽ�紵����ҡҡ�λΡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shan3",
  "northwest" : __DIR__"shan5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
