// Room: /wiz/louth/a/shan6.c

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
  "westdown" : __DIR__"shan5",
  "westup" : __DIR__"shan7",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
