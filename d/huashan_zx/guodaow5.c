// Room: guodaow5.c by pian
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ����ԶԶ����
����������̨����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"guodaow6",
	"southeast" : __DIR__"guodaow4",
	//"west":__DIR__"longbi2",
	"east":__DIR__"huacong2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}