//dangpu.c ��֥��ĵ���
inherit HOCKSHOP;
void create()
{
        set("short", "�������ϵ���");
        set("long", @LONG
��������֥��Ψһ��һ�ҵ��̣���Ȼ�������ҵ�����ر�
�٣�����������֥�����ص����˿ڱȽ��ܼ��ĵ��������̵�����
�����൱����һ����ӭ����һ�����ӣ�paizi���������ϰ���
�ڸ߸ߵĹ�̨���濴���㡣
LONG
        );
        set("item_desc", ([
                "paizi": @TEXT
[value | gujia ]     : ����
[pawn  | dang  ]     : �䵱������ҵ����ͣ��
[sell          ]     : ��
[redeem| shu   ]     : ���
[list          ]     : �б�
[ buy  | mai   ]     : ��
TEXT
]));
        set("exits", ([
        "north":__DIR__"lz_eroad2",
        ]));
        set("objects",([
                __DIR__"npc/d_boss":1,
]));
        setup();
}
