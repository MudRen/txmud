// Room: /d/tangmen/xiaowu.c

inherit ROOM;

void create()
{
        set("short", "ҩׯС��");
	set("long", @LONG
ӭ�ŵ�ǽ�Ϲ���һ������ͼ����ǽ��һ����ױ̨��һ������
ɫ��װ�ĸ�����ǽ�����������ϣ�һ������һҳֽ��һ�ָ�Ħ��
һ��������ױ̨�ϵľ��顣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"yz_xiaoyuan",
]));

	set("objects", ([
//	__DIR__"npc/tangfuren" : 1,
]));

        set("item_desc", ([
       "ֽ":"�ƺ�����д�˼����֣�һ�Ǳ���ѹס����������\n",
       "paper":"�ƺ�����д�˼����֣�һ�Ǳ���ѹס����������\n",
       "��":"�������п࣬X X �����ᡣ\n",
       "zi":"�������п࣬X X �����ᡣ\n",
       "book":"��ҳ�ܻƣ������ܾ�Զ�ˣ���Ϊ����ѹ�ţ�����������д��ʲô��\n",
       "����":"��ҳ�ܻƣ������ܾ�Զ�ˣ���Ϊ����ѹ�ţ�����������д��ʲô��\n",
]));

	setup();
	replace_program(ROOM);
}
