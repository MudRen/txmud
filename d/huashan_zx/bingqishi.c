// Room: doorgd.c by pian
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@LONG
���������ϼ�������ң���������Ǹɾ������ֱ��������
���ڱ������ϣ�������û�з��У�����ֻ�ǹ������õġ����ɵ�
�ӿ��Ե�����ȡ���ֵı���ȥ��ϰ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"guodaow2",
]));

	set("objects",([
	WEAPON_DIR"thin_sword" : 5,
	WEAPON_DIR"bamboo_sword" : 3,
]));

	setup();
	replace_program(ROOM);
}