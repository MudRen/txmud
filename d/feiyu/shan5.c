// Room: /wiz/louth/a/shan5.c

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
  "southeast" : __DIR__"shan4",
  "eastup" : __DIR__"shan6",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
