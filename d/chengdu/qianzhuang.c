// Room: /wiz/louth/c/qianzhuang.c

inherit BANK;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
�����ǳɶ��ĺͼ�Ǯׯ���ͼ�Ǯׯӵ���ϰ������ʷ������
�Ѿ��ǽ�����һ������ͷ��Ǯׯ���ſڵĺ�ľ����(paizi)��д��
�����֡������������߾�����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao2",
]));
        set("item_desc", ([ /* sizeof() == 2 */
        "paizi" :  "��ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan           ת��
",
]));

	set("objects",([
                __DIR__"npc/banker" :1,        
        ]));

	setup();
}
