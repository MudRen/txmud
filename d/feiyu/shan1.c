// Room: /wiz/louth/a/shan1.c

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
  "westup" : __DIR__"shan2",
  "southdown" : __DIR__"shanlu5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
