// Room: guodaow3.c
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
	"northwest" : __DIR__"guodaow4",
	"southeast" : __DIR__"guodaow2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}