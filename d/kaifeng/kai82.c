inherit BANK;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
���ǿ����������һ��Ǯׯ��������Ѿ��м��������ʷ
�ˡ����÷ǳ��ã���ȫ�����ض��зֵꡣǮׯ��������Ʊ���߱�
���¶���ͨ�ã����̿��ã�������·��Я���������㣬�Ϳ��Ե�
����Ǯׯȥ������Ʊ������̨�Ϸ�����һ������(paizi)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai80",
]));

        set("item_desc", ([
	"paizi" :  "����ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת��
",
]));

        set("objects",([
        __DIR__"npc/jin": 1,
]));

	setup();
}
