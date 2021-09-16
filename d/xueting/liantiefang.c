// liantiefang.c
//
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
һֻͨ��Ļ�¯�������������룬�Ա��в��ٵ�������ææµ
µ�ذѿ�ʯ��̿�ӵ�¯��ұ�����ۣ������ߵ��ϸ��Ȼ����һ���
����������ʲô���������ְɣ����Ϲ���һ�����ӣ�Sign����
LONG
        );
	set(SAFE_ENV, 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" :__DIR__"epath",
        ]));
        set("item_desc", ([
"sign": @TEXT
��������ʹ����:
���            ˵����    ԭ�ϣ�
==========================================================
shao xuantie 	: ��������
shao wujin	: �����ڽ�
shao baijin     : ���ư׽�
shao hongtie    : ���ƺ���
shao zitie      : ��������
shao lvtie      : ��������  �����̿�ʯ ���ź�̿
shao qingtong   : ������ͭ  ������ͭʯ ���ź�̿
=================================Update By pian 2002.11.29

TEXT
        ]) );
}

void init()
{
        add_action("do_shao", "shao");
}
int do_shao(string arg)
{
        object me,ob;
        int i,sk;
        me = this_player();
        sk = me->query_skill("caikuang");
        sk = sk + sk;
        
        if( (arg != "qingtong") && (arg != "lvtie") )
		return notify_fail("��������ʲô����\n");
        
        if(me->query("kee")<20)
        	return notify_fail("������������ˣ���������Ϣһ�°ɡ�\n");
        	
        if(me->query("gin")<20)
        	return notify_fail("��ľ��������ˣ���������Ϣһ�°ɡ�\n");

//        me->start_busy(2);
        message_vision("$N����ʮ�ָ����������������ȥ����\n", me);
        message_vision("$Nֻ���ӿ���ϵ���������ʯͷ�����ͷȥѰ�ҡ�\n",me);

        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 �Ƿ���Եõ�xuantie
	if ((sk>250) && (random(sk+i))>( (sk+90)*999/1000) )
	{
		message_vision("$N�ڵ�һ������ʯ!!!\n", me);
                me->receive_damage("kee", 20);
        	me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 500);
                ob = new(__DIR__"obj/xuantie_stone");      
                ob->move(me);
                return 1;
        }
        
        //2 �Ƿ���Եõ�wujin
        if ((sk>200) && (random(sk+i))>((sk+85)*999/1000))
	{
		message_vision("$N�ڵ�һ���ڽ�ʯ!!!\n", me);
                me->receive_damage("kee", 20);
	        me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 100);
                ob = new(__DIR__"obj/wujin_stone");      
                ob->move(me);
                return 1;
        }
        
        //3 �Ƿ���Եõ�baijin
        if ((sk>160) && (random(sk+i))>((sk+80)*999/1000))
	{
		message_vision("$N�ڵ�һ�Ű׽�ʯ!!!\n", me);
                me->receive_damage("kee", 15);
        	me->receive_damage("gin", 15);
                me->improve_skill("caikuang", 50);
                ob = new(__DIR__"obj/baijin_stone");      
                ob->move(me);
                return 1;
        }
        
        //4
        if ((sk>120) && (random(sk+i))>((sk+75)*999/1000))
	{
		message_vision("$N�ڵ�һ�ź��ʯ!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 25);
                ob = new(__DIR__"obj/hongkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //5
        if ((sk>80) && (random(sk+i))>((sk+70)*999/1000))
	{
		message_vision("$N�ڵ�һ�ź��ʯ!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 15);
                ob = new(__DIR__"obj/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>50) && (random(sk+i))>((sk+65)*999/1000))
	{
		message_vision("$N�ڵ�һ���̿�ʯ!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 10);
                ob = new(__DIR__"obj/lvkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+70)*9/10))
	{
		message_vision("$N�ڵ�һ����ͭʯ!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 3);
                ob = new(__DIR__"obj/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$Nֻ���ӿ���ϵ���������ʯͷ����ʲôҲû�еõ���\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("caikuang", 1);
        return 1;
        
}