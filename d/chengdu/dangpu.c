// Room: /wiz/louth/c/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ܴ�����ã��ſڵ�������ӡ��һ�����ġ�����
�֡���̨����һ�˸ߣ����滹������դ������̨�ﲻ�ϴ�������
���ͻ�Ƶ�ߺ��������̨��������һ��ľ��(sign)��
LONG
);

	set("item_desc", ([
		"sign": @TEXT
�����������ҵ��:
[ value | gujia ]     : ����
[ pawn | dang ]       : �䵱
sell                  : ��
[ redeem | shu ]      : ���
list                  : �б�
[ buy | mai ]         : ��
TEXT
        ]) );


	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie4",
]));

        set("objects",([
        __DIR__"npc/jiang" : 1,
]));
	setup();
}
