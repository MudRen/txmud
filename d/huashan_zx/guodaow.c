// Room: guodaow.c
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
	"east" : __DIR__"yingbi",
	"west" : __DIR__"guodaow2",
	"northeast":__DIR__"shidao1",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}