// /d/hangzhou/bank.c

inherit BANK;

void create()
{
        set("short", "�ͼ�Ǯׯ");
        set("long", @LONG
���ݴ��ڽ�ͨҪ������������ḻ���羰�����������Ǹ���
֮�أ�Ǯׯ�����⵱Ȼ�Ǵ��˵ģ��ͼ���Ʊͨ���ϱ���������
�����Σ�����ϲ�Դ�������˵�����Ȼ����ȴ�Ƿ���ɭ�ϡ�
��˵�ƹ�ı��˸��������˵á��ſ�����һ��ͭ��(pai)��
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw2",
]));


        set("item_desc", ([ /* sizeof() == 2 */
"pai" : "�ͼ�ǮׯĿǰ�����ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת��
",
]));

	set("no_beg", 1);
	set("objects",([
	__DIR__"npc/banker" : 1,
]));
        setup();
}
