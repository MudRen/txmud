#include <ansi.h>
#include <command.h>
inherit NPC;

int do_liandan();

void create()
{
        set_name(YEL"ҩͯ"NOR, ({"yao tong", "tong"}));
        set("gender", "����");
        set("age", 16);
        set("long", 
                "��ҩ�����Сҩͯ�����ԭ�ϸ����������������(liandan)��\n");
        set("attitude", "peaceful");             
        
        set("combat_exp", 1500);
       
        set_skill("force", 10); 
        set_skill("unarmed", 10); 
        set_skill("dodge", 10); 
        set_skill("parry", 10);          

        set("inquiry", ([
                "����" : (: do_liandan :),
        ]) );
       
        setup();
        //carry_object("clone/cloth/cloth")->wear();
}

int do_liandan()
{      
        object me;
        me = this_player(); 
              command("say ���Һ��ʵ�ԭ�Ͼ�������������(liandan)�ˡ�\n");
               return 1;     
   
}
int accept_object(object me, object ob)
{
        int n;
        string na=ob->query("name");
       
  if(na==YEL"��ͨҩ��"NOR&&ob->query("canoe")) n=2000;
                  // query("canoe") ��ݼ���
        else if (na==HIY"���ҩ��"NOR&&ob->query("canoe")) n=4000;
        
        else{ 
         	   command("say ������������������Ϻõ�ԭ����\n");
        	    return 0;
      	    }
      	    

        if (me->query_temp("yxld") )
             {
             command("say �ϴεĵ���û�����꣬��ô�������ˣ�\n");
             return 0;
             }
        
      	  
        message_vision("Сҩͯ�ӹ�"+na+"������Ͷ����ҩ¯��\n"NOR,me);
    	message_vision(CYN"С��ͯ˵����$N,����Կ�ʼ��(liandan)�ˣ���ס����(liandan)�Ĵ���Խ�࣬����Խ��ġ�\n�������������stopֹͣ������û�н�����Ŷ��\n"NOR,me);  
    	me->set_temp("yxld",1);
    	me->set_temp("ldwp",n);      
    	call_out("destroying", 1, this_object(), ob);
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
