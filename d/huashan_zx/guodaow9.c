// Room: guodaow9.c by pian
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
	"east" : __DIR__"guodaoe10",
	"west" : __DIR__"guodaow8",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}