// Room: jiufang2.c by pian

inherit ROOM;
void create()
{
	set("short","�Ʒ�");
	set("long",@LONG
���ǻ�ɽ�ɴ��ƵľƷ������ʦ������ȡ����Ϳ���������
���ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"westdown" : __DIR__"jiujiao",
	"south":__DIR__"guodaoe8",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}