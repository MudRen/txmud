// Room: /wiz/louth/a/xlu4.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ�����۵��ּ�С·��·���Ǹߴ�İ���������������
��Ũ�ܵ���Ҷ��͸����£�һ��΢�紵������Ҷɳɳ���졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xlu3",
  "west" : __DIR__"xlu5",
]));
 
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
