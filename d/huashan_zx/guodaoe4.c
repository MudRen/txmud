// Room: guodaoe4.c by pian
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��������Ժ�м�
��һСƬ�ݵء�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guodaoe3",
	"northeast" : __DIR__"guodaoe5",
	"west":__DIR__"caodi2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}