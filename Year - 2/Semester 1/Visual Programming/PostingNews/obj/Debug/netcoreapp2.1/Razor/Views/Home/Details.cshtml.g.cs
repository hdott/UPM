#pragma checksum "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "c908cb95d8b17f122bd1825ecfe28b6d719552e9"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Home_Details), @"mvc.1.0.view", @"/Views/Home/Details.cshtml")]
[assembly:global::Microsoft.AspNetCore.Mvc.Razor.Compilation.RazorViewAttribute(@"/Views/Home/Details.cshtml", typeof(AspNetCore.Views_Home_Details))]
namespace AspNetCore
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.Rendering;
    using Microsoft.AspNetCore.Mvc.ViewFeatures;
#line 1 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\_ViewImports.cshtml"
using PostingNews;

#line default
#line hidden
#line 2 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\_ViewImports.cshtml"
using PostingNews.Models;

#line default
#line hidden
#line 3 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\_ViewImports.cshtml"
using PostingNews.ViewModels;

#line default
#line hidden
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"c908cb95d8b17f122bd1825ecfe28b6d719552e9", @"/Views/Home/Details.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"a6c8d19542fe2d761b12013fb63f3b0ebd271b35", @"/Views/_ViewImports.cshtml")]
    public class Views_Home_Details : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<Post>
    {
        #pragma warning disable 1998
        public async override global::System.Threading.Tasks.Task ExecuteAsync()
        {
            BeginContext(13, 21, true);
            WriteLiteral("\r\n<div class=\"row\">\r\n");
            EndContext();
#line 4 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
     if (string.IsNullOrEmpty(Model.URL))
    {

#line default
#line hidden
            BeginContext(84, 12, true);
            WriteLiteral("        <h2>");
            EndContext();
            BeginContext(97, 11, false);
#line 6 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
       Write(Model.Title);

#line default
#line hidden
            EndContext();
            BeginContext(108, 7, true);
            WriteLiteral("</h2>\r\n");
            EndContext();
#line 7 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
    }
    else
    {

#line default
#line hidden
            BeginContext(139, 14, true);
            WriteLiteral("        <h2><a");
            EndContext();
            BeginWriteAttribute("href", " href=\"", 153, "\"", 170, 1);
#line 10 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
WriteAttributeValue("", 160, Model.URL, 160, 10, false);

#line default
#line hidden
            EndWriteAttribute();
            BeginContext(171, 1, true);
            WriteLiteral(">");
            EndContext();
            BeginContext(173, 11, false);
#line 10 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
                            Write(Model.Title);

#line default
#line hidden
            EndContext();
            BeginContext(184, 11, true);
            WriteLiteral("</a></h2>\r\n");
            EndContext();
#line 11 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
    }

#line default
#line hidden
            BeginContext(202, 7, true);
            WriteLiteral("    <p>");
            EndContext();
            BeginContext(210, 17, false);
#line 12 "C:\Users\nhori\Git\UPM\Year - 2\Semester 1\Visual Programming\PostingNews\Views\Home\Details.cshtml"
  Write(Model.Description);

#line default
#line hidden
            EndContext();
            BeginContext(227, 12, true);
            WriteLiteral("</p>\r\n</div>");
            EndContext();
        }
        #pragma warning restore 1998
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.ViewFeatures.IModelExpressionProvider ModelExpressionProvider { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IUrlHelper Url { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IViewComponentHelper Component { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IJsonHelper Json { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IHtmlHelper<Post> Html { get; private set; }
    }
}
#pragma warning restore 1591
