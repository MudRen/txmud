// Room: guodaow8.c by pian
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ������з������Ʈ����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"guodaow9",
	"southwest" : __DIR__"guodaow7",
	"north":__DIR__"chufang1",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}