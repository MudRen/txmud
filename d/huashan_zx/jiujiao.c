// Room: jiujiao.c by pian

inherit ROOM;
void create()
{
	set("short","�ƽ�");
	set("long",@LONG
���ǻ�ɽ�ɴ��Ƶľƽѣ����ʦ������ȡ����Ϳ���������
���ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"eastup" : __DIR__"jiufang",
	//"south":__DIR__"guodaoe8",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}