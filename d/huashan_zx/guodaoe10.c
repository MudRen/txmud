// Room: guodaoe10.c by pian
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"guodaoe9",
	"west" : __DIR__"guodaow9",
	"north":__DIR__"houmen",
	"south":__DIR__"houdian",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}