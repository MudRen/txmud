// Room: guodaow4.c
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����ǵ��̵�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"northwest" : __DIR__"guodaow5",
	"southeast" : __DIR__"guodaow3",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}