// Room: /wiz/uudd/path2/minjv01.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
��������߲��Ǻܺã�����Ҳ�е����˲����ܣ������Ǵ���
ʲô��һ��ζ�����㲻����������ӣ��������ܣ�����û��ʲô
�Ҿߣ�һ��ľ���������ӵ����룬һ��Сľ������ǽ�ǣ��Ա���
һ����ľ�����������Ѿ��ò��˶���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s11",
]));

	setup();
	replace_program(ROOM);
}
