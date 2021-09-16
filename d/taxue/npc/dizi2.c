// dizi2.c
// by dicky

inherit NPC;
string ask_xiashan();

#include <ansi.h>

void create()
{
	set_name("̤ѩΣ��", ({ "taxue weifang","weifang", "man" }));
	set("class","taxue");
	set("nickname", HIC"̤ѩɽׯѲʹ"NOR);
        create_family("̤ѩɽׯ", 2, "����");
	set("gender", "����");
	set("age", 40);  
	set("long", "����ׯ��̤ѩ��Զ�ڶ������ӣ�������ɽׯ��Ѳ�ӣ��������Ƚ����ϡ�\n");

        set("startroom","/d/taxue/xiting");

        set("chat_chance", 10);
        set("chat_msg", ({            
                 (: random_move :)
        }) );

	set("combat_exp", 400000);
        set("max_kee",2200);
        set("max_gin",2200);
        set("max_sen",2200);
        set("max_force", 2800);
        set("max_atman", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);

        set_skill("literate",150);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("sword",150);	

	set("inquiry",([
           "��ɽ" : (: ask_xiashan :),
           "xiashan" : (: ask_xiashan :),
	]));

     
        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
      object where;
      string startxx;
      startxx= "/d/changan/jiulou";
      where = environment(ob);
      if( !ob || environment(ob) != environment() ) return; 
      if (ob->query("combat_exp") >2000000) return;       
      if ( ob->query("class") =="taxue") return;
      if (wizardp(ob)) return;
      command("why "+ ob->query("id"));
      command("say ��λ" + RANK_D->query_respect(ob)+ "���㲻�Ǳ�ɽׯ�ĵ��ӣ���ô�ܵ�ɽׯ���ˣ�\n"+"̤ѩɽׯ���������������ģ�ϣ���㲻Ҫ�����ڴ˵��ˡ�\n");
      write (HIR"ֻ����һ�����˰����㱻һ������������ˡ�\n"NOR);
      ob ->unconcious();
      command("get all from "+ob->query("id"));
      command("drop all");
      ob ->move("/d/houjizhen/shanya");
      ob->set("startroom",startxx);
}

string ask_xiashan()
{
	object ob,me;
	ob=this_player();
	me=this_object();

	if(ob->query("class")!="taxue")
             return "�ٺ٣�����ɽ��û����ô���׵����飿";

	if(ob->query("combat_exp")<1000000)
             return "��ľ��鲻�������ǲ�Ҫ��ɽ�ĺã���������涪̤ѩɽׯ������";

	if(ob->query_skill("taxue-force", 1) < 180 
	&& ob->query_skill("fenghui-sword", 1) < 180
	&& ob->query_skill("dodge", 1) < 180) 
             return "�Ǻǣ�ׯ���Ը����ˣ��������µ��ӽ�ֹ��ɽ��";
/*
	if(sizeof(filter_array(deep_inventory(ob),(: $1->is_taxue_book() :))))
	    return "ׯ���Ը���̤ѩɽׯ���鼮��ֹ����ɽ�������Ǿ�����ɽ�����������鼮�����Լ�ѡ����ˣ�\n";
*/

	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "�������ܳ�ɽ������������硣\n");
	tell_room(environment(ob), ob->name() + "ͻȻ��̤ѩΣ��ץ��գ�۾���ʧ�����ˡ�\n", ({ ob }));
	tell_object(ob, HIB"��ͻȻ��̤ѩΣ��ץ���������磬һգ�ۼ������ɽ�±ߡ�\n\n"NOR);
      	command("get all from "+ob->query("id"));
	ob->move("/d/taxue/yashang");
	me->move("/d/taxue/yashang");
	tell_room(environment(ob), ob->name() + "��̤ѩΣ��ͻȻ�����������ǰ��\n", ({ ob }));
	tell_object(ob, HIB"ͻȻ�㱻̤ѩΣ������˦�˳�ȥ��������о��йɾ޴�����������㣬\n��æ�����ڹ����������������������ɽ����Ʈ��ȥ��\n\n"NOR);
	ob->start_busy(2);
	ob->move("/d/houjizhen/shanya");
	tell_room(environment(ob), ob->name() + "ͻȻ��ɽ���Ϸ���������\n", ({ ob }));
	return HIY"��������һ������������ɽ���ˣ�"NOR;
}
