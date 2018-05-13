#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "er" }) );
        set("nickname", HIC "��Ϣ��ͨ" NOR);
        set("gender", "����" );
        set("age", 22);
        set("long",
                "һ��Ц���еĵ�С�����ǻ�Ӣ��¥�еĻ�ơ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
                "/d/city/obj/jitui",
                "/d/city/obj/jiudai",
                "/d/city/obj/baozi",
                "/d/beijing/obj/mian",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");

        if ( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment() ) return;
        switch( random(2) )
        {
        case 0:
                say( CYN "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "����ӭ������Ӣ��¥��\n" NOR);
                break;
        case 1:
                say( CYN "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "�������������Ӣ��¥�ò�ô��\n" NOR);
                break;
        }
}
