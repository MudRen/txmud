// Room: guodaow6.c by pian
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
	set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"guodaow7",
	"southwest" : __DIR__"guodaow5",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}