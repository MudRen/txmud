// Room: guodaow2.c
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
	"east" : __DIR__"guodaow",
	"northwest" : __DIR__"guodaow3",
	"south":__DIR__"bingqishi",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}