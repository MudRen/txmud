// Room: guodaoe3.c by pian
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
	"southwest" : __DIR__"guodaoe2",
	"northeast" : __DIR__"guodaoe4",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}