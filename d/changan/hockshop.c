// Room: /d/changan/hockshop.c ����

inherit HOCKSHOP;

void create()
{
        set("short", "�ܼǵ���");
        set("long", @LONG
�����ǳ�����һ�Һܴ�ĵ��̣�һ���ţ���㿴���˸߸ߵ�
��̨����̨��һ��һ���Һ�ĵ��ϰ壬����æ�ŵ��ű��˵Ķ�����
����ͣ�Ľ��ţ��յ�����ĳĳһ����ֵ���١��Աߵ��ʷ�������
�����ʣ�������������⻹������¡���ſ���һ���ͺڷ�������
��(sign)�����ó�������Ѿ��ܹ����ˡ���������������ȸ��
�֡�
LONG
        );
        set("item_desc", ([
                "sign": @TEXT
���̽��׵ķ���:
[ value | gujia ]     : ����
[ pawn | dang ]       : �䵱
sell                  : ��
[ redeem | shu ]      : ���
list                  : �б�
[ buy | mai ]         : ��
TEXT
        ]) );
        set("exits", ([
                "south" : __DIR__"nroad6",
        ]));

	set("objects",([
		__DIR__"npc/zhou_xc"	: 1,
]));
        setup();
}