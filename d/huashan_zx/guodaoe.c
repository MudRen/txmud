// Room: guodaoe.c by pian
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
	"west" : __DIR__"yingbi",
	"east" : __DIR__"guodaoe2",
	"northwest":__DIR__"shidao1",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}